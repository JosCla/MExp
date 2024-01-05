#!/bin/bash

# ensuring the application file is present
if [ ! -e MExp.8xk ]; then
    echo "Could not find MExp.8xk. Exiting."
    exit
fi

# signing the application file
rabbitsign -r -g MExp.8xk
mv MExp.8xk MExp-unsigned.8xk
mv MExp-signed.8xk MExp.8xk

# remove working folders
rm -r locked
rm -r MExp

# make locked folder, put "end" contents inside
mkdir locked
cp -r end-dir/* locked

areas=("cliffs:big-scalar,whimsy-raft" "lake:icy-lake,caustic-bluff" "foothills:the-rescue,obscured-mirror" "islands:log-maze,raft-ejection")
for area in ${areas[@]}; do
    name=$(echo "$area" | cut -d ":" -f 1)
    digressions=$(echo "$area" | cut -d ":" -f 2 | tr "," "\n")

    # zip up existing locked folder
    password=$(cat "../maps/final/$name/password.txt")
    zip -e locked.zip -r locked -P $password

    # put locked zip along with world file in next locked folder
    rm -r locked/*
    mv locked.zip locked
    cp "../maps/final/$name/MEXPWORL.8xv" locked
    cp -r "$name"/* locked

    # zip up digressions and put them in a secrets folder in locked
    if [ ${#digressions} -gt 0 ]; then
        mkdir locked/secrets

        digInd=1
        for d in $digressions; do
            dFolder="secret-$digInd"
            mkdir $dFolder
            cp "../maps/final/digressions/$d/MEXPWORL.8xv" $dFolder

            dPassword=$(cat "../maps/final/digressions/$d/password.txt")
            zip -e "$dFolder.zip" -r $dFolder -P $dPassword

            mv "$dFolder.zip" locked/secrets
            rm -r $dFolder

            ((++digInd))
        done
    fi
done

# take stuff out of locked folder, put it in a MExp folder
mkdir MExp
mv locked/* MExp
rmdir locked

# copy in all the start stuff
cp -r start-dir/* MExp

# copy in the application itself
cp MExp.8xk MExp

# zip it up
zip MExp.zip -r MExp

# folder cleanup
rm -r MExp
