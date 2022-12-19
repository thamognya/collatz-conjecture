#!/bin/sh

# run root

cp -r ./collatzconjecture.service /etc/systemd/system/
systemctl daemon-reload
systemctl enable collatzconjecture.service
systemctl restart collatzconjecture.service
