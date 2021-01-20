# Menu script
while true ; do
echo " 0: Exit"
echo " 1: Show Date and Time"
echo " 2: List my HOME directory"
echo " 3: Display Calendar"
echo " Enter your choice:"
read option
case $option in
0)	echo "good bye"
	exit 0 ;;
1)	date ;;
2)	ls $HOME ;;
     3) cal ;;
     *) echo "Invalid input. Good bye." ;;
esac
done
