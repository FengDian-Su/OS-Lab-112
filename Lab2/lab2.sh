GuessNumber(){
	start=1
	final=10
	echo "Enter the target number between 1 and 10"
	read num
	echo "Enter the target number:"
	read input
	while [ $input -ne $num ]; do
		if [ $input -lt $num ]; then
			start=$input
		elif [ $input -gt $num ]; then
			final=`expr $input + 1`
		else
			echo "Bingo!"
		fi
		echo "Enter the target number between $start and $final:"
		echo "Enter the target number:"
		read input
	done
	echo "Bingo!"
}
GuessNumber;
