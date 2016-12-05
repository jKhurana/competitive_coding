if [ -d "$1" ]; then
	echo "Directory alerady exist"
	exit 1
fi
mkdir $1
cd $1
for index in 1 2 3 4 5 6 7 8 9 10
do
	cp ../../standardalgorithm/CPPTemplate.cpp ./
	mv CPPTemplate.cpp $index.cc
done
echo "Successful!!"
