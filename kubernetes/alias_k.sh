#!/bin/bash

echo "alias k=\"microk8s kubectl\"" >> $HOME/.bash_aliases
exec bash
