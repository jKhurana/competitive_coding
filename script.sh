read -p "Enter website name : " websitename
read -p "Enter contestname : " contestname
read -p "Enter number of porblem : " n
cd $websitename
mkdir $contestname
cd $contestname
for((i=1;i<=$n;i++))
do
mkdir "P"$i
done
echo "Directory strucutre created succefully"
codeblocks &
