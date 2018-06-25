<form method="POST" action="#">
  <input type="text" name="pri" placeholder="please enter the number">
   <button type="submit" name="number">Primes</button>                  
  </form>


<?php
if(isset($_POST['number']))
{
$num = 2 ;
while ($num < $_POST['pri'] )
{
$c=0;
for ( $i=1;$i<=$num;$i++)
{
if (($num%$i)==0)
{
$c++;
}
}
if ($c<3)
{
echo $num."   ";
}
$num++;
}
}
?>