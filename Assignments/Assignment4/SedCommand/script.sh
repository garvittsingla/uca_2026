#!/bin/zsh

sed 's/1.0/1.1/g' input.txt | sed '/^#/d' | sed -E "s/[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}/xxxx-xxxx-xxxx/" | sed -E "s/[0-9]{16}/xxxx-xxxx-xxxx/" > output.txt