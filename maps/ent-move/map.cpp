int main() {
    // MEIDAT
    Calc8XvFile mapFile;
    mapFile.set_name("MEIDAT");
    mapFile.set_comment("MExp Island Data");
    mapFile.set_archived(true);

    vector<char> ents = {
        '\x0f', '\x00',
        '\x20', '\x00',
        '\x28', '\x00',
        '\x38', '\x00',
        '\x44', '\x00',
        '\x54', '\x00',

        '\x00', '\x01', '\x02', '\x00', '\x00', '\x00', '\x00', '\x00',

        '\x01', '\x04', '\x01', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x01', '\x05', '\x01', '\x02', '\x01', '\x02', '\x00', '\x00',

        '\x01', '\x0d', '\x01', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x03', '\x0e', '\x01', '\x03', '\x01', '\x02', '\x00', '\x00',

        '\x01', '\x15', '\x01', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x01', '\x16', '\x01', '\x04', '\x01', '\x02', '\x00', '\x00',

        '\x01', '\x15', '\x01', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x01', '\x16', '\x01', '\x04', '\x01', '\x02', '\x00', '\x00',
    };

    string res = "";
    for (char c : ents) {res += c;}
    mapFile.set_data(res);

    mapFile.write();

    return 0;


    // MEIMAP
    Calc8XvFile mapFile;
    mapFile.set_name("MEIMAP");
    mapFile.set_comment("MExp Island Map");
    mapFile.set_archived(true);

    vector<string> map = {
        "011000000000000000000000000000000000",
        "011022222220333333r04444444440000000",
        "011000000000000000000000000000888800",
        "000000000000000000000777777r00888800",
        "0555555555006666666r0777777r00000000",
        "000000000000000660000077777r00000000",
        "0rr0r0aa00bbb00r0ccccc0000000000r000",
        "0000000a00b0b00000cccc00dd00000r0000",
        "00r0000a0000000000cccc00dd0000eeee00",
        "0r00000a00bb000000cccc00dd00eeeee000",
        "099000000000000000000000dd00eeeeeeer",
        "0000000000b0b00000000000000000000000",
    };

    string res = "";
    res += (int)map.at(0).size();
    res += (int)map.size();
    for (string row : map) {
        for (char c : row) {
            if (c == 'r') {
                res += 255;
            } else {
                int cInt = (int)c;
                if (cInt > (int)'a') {
                    res += cInt - (int)'a';
                } else {
                    res += cInt - (int)'0';
                }
            }
        }
    }
    mapFile.set_data(res);

    mapFile.write();

    return 0;


    // MEHMAP
    Calc8XvFile mapFile;
    mapFile.set_name("MEHMAP");
    mapFile.set_comment("MExp Height Map");
    mapFile.set_archived(true);

    vector<string> map = {
        "011000000000000000000000000000000000",
        "011011111110111111101112233230000000",
        "011000000000000000000000000000111100",
        "000000000000000000000333111100111100",
        "033332212300111111110333111100000000",
        "000000000000000110000033111100000000",
        "011010110011100101112300000000001000",
        "000000020010100000999400110000010000",
        "001000010000000000926500110000111100",
        "010000030011000000887600110011111000",
        "011000000000000000000000660011111111",
        "000000000010100000000000000000000000",
    };

    string res = "";
    res += (int)map.at(0).size();
    res += (int)map.size();
    for (string row : map) {
        for (char c : row) {
            if (c == 'r') {
                res += 255;
            } else {
                res += ((int)c - (int)'0');
            }
        }
    }
    mapFile.set_data(res);

    mapFile.write();

    return 0;
}
