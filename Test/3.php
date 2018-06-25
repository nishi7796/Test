<form method="post" action="#">
  <input type="text" name="websiteurl" placeholder="Enter links">
   <button type="submit" name="surflinks">Surf links</button>                  
  </form>
  <?php
  if(isset($_POST['surflinks']))
{
 $srcUrl=$_POST['websiteurl'];
$html = file_get_contents($srcUrl);
 
$domain = new DOMDocument();
@$domain->loadHTML($html);
 $xpath = new DOMXPath($domain);
 
$hrefs = $xpath->evaluate("/html/body//a");
 

for ($i = 0; $i < $hrefs->length; $i++)
	{
       $href = $hrefs->item($i);
       $url = $href->getAttribute('href');
	   if($url!='#')
	   {
      echo "".$url."<br>";
	   }
}
}
  ?>