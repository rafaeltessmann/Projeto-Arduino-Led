<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Tesla Web</title>
    <meta name="description" content="Free Bootstrap Theme by uicookies.com">
    <meta name="keywords" content="free website templates, free bootstrap themes, free template, free bootstrap, free website template">
    <link href="https://fonts.googleapis.com/css?family=Open+Sans:300,400" rel="stylesheet">
    <link rel="stylesheet" href="css/styles-merged.css">
    <link rel="stylesheet" href="css/style.min.css">
    <link rel="stylesheet" href="css/custom.css">
    
</head>
<!-- 
    led1 = sala 
    led3 = banheiro
    led4 = q1
    led5 = q2
-->
<body onload="reload()">
    <div class="probootstrap-loader"></div>

    <header role="banner" class="probootstrap-header">
        <div class="container">
            <a href="index.php" class="probootstrap-logo">Tesla Web<span>.</span></a>

            <a href="#" class="probootstrap-burger-menu visible-xs"><i>Menu</i></a>
            <div class="mobile-menu-overlay"></div>

            <nav role="navigation" class="probootstrap-nav hidden-xs">
                <ul class="probootstrap-main-nav">
                    <li><a href="index.php">inicio</a></li>
                    <li><a href="projeto.html">o projeto</a></li>
                    <li><a href="equipe.html">Grupo</a></li>
                </ul>
            </nav>
        </div>
    </header>
    <section class="page-title">    
        <div class="container">
            <h1>Controle da iluminação do protótipo</h1>
            <form name="formulario" action = "arduino.php" method = "post">                
                <div class="col-md-10">   
                    <div class="row">
                        <?php // salacozinha
                            if (!(isset($_GET['led3'])) || 
                                ((isset($_GET['led3'])) && 
                                ($_GET['led3'] == 0))){
                        ?>
                            <button 
                                name="led"                             
                                type="submit" 
                                class="botao" 
                                style="width: 60%;" 
                                value="led3on"
                            >
                                <img 
                                    src="img/q1_off.png" 
                                    alt="luz do quarto apagada" 
                                    class="img-responsive" 
                                    style="float: left;"
                                />
                            </button>
                        <?php } else { ?>
                            <button 
                                name="led"                             
                                type="submit" 
                                class="botao" 
                                style="width: 60%;" 
                                value="led3off"
                            >
                                <img 
                                    src="img/q1_on.png" 
                                    alt="luz do quarto acesa" 
                                    class="img-responsive" 
                                    style="float: left;"
                                />
                            </button>
                        <?php } 
                            if (!(isset($_GET['cooler'])) || 
                                ((isset($_GET['cooler'])) && 
                                ($_GET['cooler'] == 0))){
                        ?>
                            <button 
                                name="led"                             
                                type="submit" 
                                class="botao" 
                                style="width: 10%;" 
                                value="coolerOn"
                            >
                                <img 
                                    src="img/v_on.gif" 
                                    alt="lventilador desligado" 
                                    class="img-responsive" 
                                    style="float: left;"
                                />
                            </button>
                        <?php } else { ?>
                            <button 
                                name="led"                            
                                type="submit" 
                                class="botao" 
                                style="width: 10%;" 
                                value="coolerOff"
                            >
                                <img 
                                    src="img/v_off.png" 
                                    alt="ventilador ligado" 
                                    class="img-responsive" 
                                    style="float: left;"
                                />
                            </button>
                        <?php } ?>
                    </div>
                    <div style="align-items: center">    
                        <?php 
                            if (!(isset($_GET['led1'])) || 
                                ((isset($_GET['led1'])) && 
                                ($_GET['led1'] == 0))){
                        ?>
                            <button 
                                name="led"                             
                                type="submit" 
                                class="botao" 
                                style="width: 50%;" 
                                value="led1off"
                            >
                                <img 
                                    src="img/cz_off.png" 
                                    alt="luz da cozinha apagada" 
                                    class="img-responsive" 
                                    style="float: left;"
                                />
                            </button>
                        <?php } else { ?>
                            <button 
                                name="led"                             
                                type="submit" 
                                class="botao" 
                                style="width: 50%;" 
                                value="led1on"
                            >
                                <img 
                                    src="img/cz_on.png" 
                                    alt="luz da cozinha acesa" 
                                    class="img-responsive" 
                                    style="float: left;"
                                />
                            </button>
                        <?php } ?>

                        <?php // quarto 2
                            if (!(isset($_GET['led2'])) || 
                                ((isset($_GET['led2'])) && 
                                ($_GET['led2'] == 0))){
                        ?>
                            <button 
                                name="led"                             
                                type="submit" 
                                class="botao" 
                                style="width: 45%;" 
                                value="led2on"
                            >
                                <img 
                                    src="img/sl_off.png" 
                                    alt="luz dsala apagada" 
                                    class="img-responsive" 
                                    style="float: left;"
                                />
                            </button>
                        <?php } else { ?>
                            <button 
                                name="led"                             
                                type="submit" 
                                class="botao" 
                                style="width: 45%;" 
                                value="led2off"
                            >
                                <img 
                                    src="img/sl_on.png" 
                                    alt="luz da sala acesa" 
                                    class="img-responsive" 
                                    style="float: left;"
                                />
                            </button>
                        <?php } ?>
                    </div>
                </div>
            </form>
        </div>
    </section>



    <div class="gototop js-top">
        <a href="#" class="js-gotop"><i class="icon-chevron-thin-up"></i></a>
    </div>
    <script src="js/scripts.min.js"></script>
    <script src="js/main.min.js"></script>
    <script src="js/custom.js"></script>
    <script>
        function reload() {
            setTimeout(() => {
                document.formulario.submit();
            }, 5000);
        }
    </script>
</body>

</html>