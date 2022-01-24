int main() {
    // MEIDAT
    Calc8XvFile mapFile;
    mapFile.set_name("MEIDAT");
    mapFile.set_comment("MExp Island Data");
    mapFile.set_archived(true);

    vector<char> ents = {
        '\x05', '\x00', // num islands
        '\x0c', '\x00', // pointer to island 1
        '\x1c', '\x00',
        '\x2c', '\x00',
        '\x44', '\x00',
        '\x54', '\x00',

        '\x01', '\x01', '\x02', '\x00', '\x00', '\x00', '\x00', '\x00', // data on island 1 (it has 1 entity, spawnX = 1, spawnY = 2)
        '\x01', '\x02', '\x02', '\x01', '\x01', '\x01', '\x00', '\x00', // entity 1 for island 1

        '\x01', '\x06', '\x03', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x01', '\x07', '\x03', '\x02', '\x01', '\x01', '\x00', '\x00',

        '\x02', '\x04', '\x05', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x01', '\x04', '\x06', '\x03', '\x01', '\x01', '\x00', '\x00',
        '\x01', '\x05', '\x06', '\x03', '\x02', '\x01', '\x00', '\x00',

        '\x01', '\x18', '\x05', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x01', '\x19', '\x05', '\x04', '\x01', '\x01', '\x00', '\x00',

        '\x00', '\x18', '\x03', '\x00', '\x00', '\x00', '\x00', '\x00',
    };

    string res = "";
    for (char c : ents) {res += c;}
    mapFile.set_data(res);

    mapFile.write();

    return 0;


    // MEEMAP
    Calc8XvFile mapFile;
    mapFile.set_name("MEEMAP");
    mapFile.set_comment("MExp Entity Map");
    mapFile.set_archived(true);

    vector<string> map = {
        "000000000000000000000000000",
        "000000000000000000000000000",
        "001000000000000000000000000",
        "000000020000000000000000000",
        "000000000000000000000000000",
        "000000000000000000000000040",
        "000033000000000000000000000",
        "000000000000000000000000000",
        "000000000000000000000000000",
        "000000000000000000000000000"
    };

    string res = "";
    res += (int)map.at(0).size();
    res += (int)map.size();
    for (string row : map) {
        for (char c : row) {
            res += ((int)c - (int)'0');
        }
    }
    mapFile.set_data(res);

    mapFile.write();

    return 0;


    // MEIMAP
    Calc8XvFile mapFile;
    mapFile.set_name("MEIMAP");
    mapFile.set_comment("MExp Island Map");
    mapFile.set_archived(true);

    vector<string> map = {
        "000000000000000000000000000",
        "011100000000000000000000000",
        "011110022000000000000555550",
        "011110222200000000000555550",
        "001r00022000000000000000000",
        "000033300000000000000004440",
        "000333300000000000000004440",
        "00033r0000000000000000000r0",
        "000030000000000000000000000",
        "000000000000000000000000000"
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


    // MEHMAP
    Calc8XvFile mapFile;
    mapFile.set_name("MEHMAP");
    mapFile.set_comment("MExp Height Map");
    mapFile.set_archived(true);

    vector<string> map = {
        "000000000000000000000000000",
        "000000000000000000000000000",
        "000000000000000000000445440",
        "000000000000000000000432100",
        "000000000000000000000000000",
        "000000000000000000000000000",
        "000000000000000000000000000",
        "000000000000000000000000000",
        "000000000000000000000000000",
        "000000000000000000000000000"
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

    
    // MECENT
    Calc8XvFile mapFile;
    mapFile.set_name("MECENT");
    mapFile.set_comment("MExp Current Entities");
    mapFile.set_archived(true);

    vector<char> ents = {
        '\x05', '\x00', // num islands
        '\x0e', '\x00', // island 1 head pointer
        '\x1a', '\x00', // island 2 head pointer
        '\x26', '\x00', // ...
        '\x3e', '\x00',
        '\x00', '\x00', // (0 if none)

        '\x4a', '\x00', // first empty

        '\x01', '\x02', '\x02', '\x01', '\x01', '\x01', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', // (entity 1 for island 1)

        '\x01', '\x07', '\x03', '\x02', '\x01', '\x01', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',

        '\x01', '\x04', '\x06', '\x03', '\x01', '\x01', '\x00', '\x00', '\x00', '\x00', '\x32', '\x00',
        '\x01', '\x05', '\x06', '\x03', '\x02', '\x01', '\x00', '\x00', '\x26', '\x00', '\x00', '\x00',

        '\x01', '\x19', '\x05', '\x04', '\x01', '\x01', '\x00', '\x00', '\x00', '\x00',

        // 5 empty slots at end, for good measure and so we have an empty slot to point at with our first empty
        '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
        '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
    };

    string res = "";
    for (char c : ents) {res += c;}
    mapFile.set_data(res);

    mapFile.write();

    return 0;
}
