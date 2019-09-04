#!/usr/bin/perl -wT

use strict;
use CGI;
use CGI::Carp qw ( fatalsToBrowser );
use File::Basename;

$CGI::POST_MAX = 1024 * 5000;
my $safe_filename_characters = "a-zA-Z0-9_.-";
my $upload_dir = "/var/www/html/TP3_SO2/modulitos/upload"; #directorio donde se almacena el modulo cargado

my $query = new CGI; #la variable $query es una conexión muy importante para el módulo CGI,
		     #ya que le dice a perl que la función a la que hace referencia pertenece a CGI
my $filename = $query->param("archivito");

if ( !$filename )
{
print $query->header ( );
print "Seleccione un modulo para cargar";
exit;
}

my ( $name, $path, $extension ) = fileparse ( $filename,qr/\.[^.]*/ );
if($extension ne ".ko") #verificacion de extension .ko
{
    error("Usted ha ingresado un modulo con la extension incorrecta");
}
 
$filename = $name . $extension;
$filename =~ tr/ /_/;
$filename =~ s/[^$safe_filename_characters]//g;

#verificacion que nombre del modulo no presente caracteres invalidos
if ( $filename =~ /^([$safe_filename_characters]+)$/ )
{
$filename = $1;
}
else
{
die "El nombre del archivo contiene caracteres invalidos.";
}

my $upload_filehandle = $query->upload("archivito"); #se almacena el modulo

open ( UPLOADFILE, ">$upload_dir/$filename" ) or die "$!";
binmode UPLOADFILE;

while ( <$upload_filehandle> )
{
print UPLOADFILE;
}

close UPLOADFILE;

system "sudo dmesg -C"; #borra los mensajes de los modulos cargados previamente
my $carga_modulo = system ("sudo insmod $upload_dir/$filename"); # se carga el modulo
if ($carga_modulo ne 0) 
{
  error('FAIL CARGANDO MODULO!');
}
else
{
	print $query-> header ();
	print (system("dmesg"));
}

sub error  #funcion de error
{
   print $query->header(),
         $query->start_html(-title=>'Error'),
         shift,
         $query->end_html;
   exit(0);
}
