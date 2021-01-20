echo "Do you want to list the current working directory content (y/n)?"
read answer
if [[ "$answer" == "y" ]]; then
   ls -1
   exit 0
else
   echo " Exiting..."
   exit 0
fi
