#!/bin/bash
cat /etc/group|sort|cut -f3 -d:
