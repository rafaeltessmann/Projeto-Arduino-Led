<?php

$sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);

socket_connect($sock, "192.168.0.200", 80);

$valor=$_POST['led'];


if ($valor=="led1on")socket_write($sock, "GET /?led1on HTTP/1.1");

if ($valor=="led1off")socket_write($sock, "GET /?led1off HTTP/1.1");

if ($valor=="led2on")socket_write($sock, "GET /?led2on HTTP/1.1");

if ($valor=="led2off")socket_write($sock, "GET /?led2off HTTP/1.1");

if ($valor=="led3on")socket_write($sock, "GET /?led3on HTTP/1.1");

if ($valor=="led3off")socket_write($sock, "GET /?led3off HTTP/1.1");



socket_close($sock);

$response=json_decode(file_get_contents('http://192.168.0.200'));
//var_dump($response->led1);

header("Location: index.php?led1=$response->led1&led2=$response->led2");
