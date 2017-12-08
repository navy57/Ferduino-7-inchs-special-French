#ifdef USE_TFT
//---------------------------------------Tela inicial ----------------------------------------------tela =0

void mainScreen(boolean refreshAll = false)
{
  
  int ledLevel;
  int offset = 0;
  char bufferLP[16];  

    setFont(LARGE, 192, 192, 192, 0, 0, 0);
   myGLCD.setColor(238, 197, 145);
    myGLCD.print(rtc.getDOWStr(), 10, 450);   

 if ((t.date <= 9) && (t.dow == 7 ))
  {
    myGLCD.printNumI(t.date, 153, 450);
    myGLCD.print(rtc.getMonthStr(), 193, 450);
   }

else if ((t.date <= 9) && (t.dow == 1) || (t.dow == 2) || (t.dow == 4))

  {
   myGLCD.printNumI(t.date, 103, 450);
   myGLCD.print(rtc.getMonthStr(), 137, 450);  
  }

else if ((t.date <= 9) && (t.dow == 3) || (t.dow == 5))
  {
    myGLCD.printNumI(t.date, 151, 450);
    myGLCD.print(rtc.getMonthStr(), 189, 450);
   }

else if ((t.date <= 9) && (t.dow == 6))
  {
    myGLCD.printNumI(t.date, 131, 450);
    myGLCD.print(rtc.getMonthStr(), 159, 450);
   }


 else if ((t.date > 9) && (t.dow == 7 ))
{
  
   myGLCD.printNumI(t.date, 151, 450);
   myGLCD.print(rtc.getMonthStr(), 195, 450);  
  }

else if ((t.date > 9) && (t.dow == 1) || (t.dow == 2) || (t.dow == 4))

  {
   myGLCD.printNumI(t.date, 101, 450);
   myGLCD.print(rtc.getMonthStr(), 145, 450);  
  }

else if ((t.date > 9) && (t.dow == 3) || (t.dow == 5))
  {
    myGLCD.printNumI(t.date, 149, 450);
    myGLCD.print(rtc.getMonthStr(), 193, 450);
   }

else if ((t.date > 9) && (t.dow == 6))
  {
    myGLCD.printNumI(t.date, 115, 450);
    myGLCD.print(rtc.getMonthStr(), 159, 450);
   }
#ifdef Anno    
   { 
    myGLCD.printNumI(t.year, 425, 450);  //Anno
   }
#endif 

   
if ((t.date != dia) || (refreshAll == true) || (t.year != ano))
  {
    dia = t.date;
    ano = t.year;
    float lunarCycle = moonPhase(t.year, t.mon, t.date); //get a value for the lunar cycle

    LP.toCharArray(bufferLP, 16);
myGLCD.setColor(190, 190, 190);
    
    myGLCD.print(bufferLP, 103, 425); //Escreve descrição da fase lunar

    if ((lunarCycle * 100) < 0) //Print % of Full to LCD
    {
      myGLCD.print(" 0.00", 700, 425);
    }
    else
    {
      myGLCD.printNumF(lunarCycle * 100, 1, 700, 425);
    }
myGLCD.setColor(245, 245, 220);          //(255, 255, 255)
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[181])));
    myGLCD.print(buffer, 450, 425); // tabela_textos[181] = "% ILUMINADA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[182])));
    myGLCD.print(buffer, 10,425); // tabela_textos[182] = "FASE LUNAR:"
  }

  if ( refreshAll == true)                                  //Desenha elementos fixos
  {
    myGLCD.setColor(196, 136, 17);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[30])));
    myGLCD.print(buffer, 50, 14); // tabela_textos[30] = "POTENCIA DOS LEDS"

    myGLCD.setColor(192, 236, 255);

    myGLCD.print("100", 18, 40);

    for (int i = 0; i < 90; i += 10)
    {
      myGLCD.printNumI(90 - i, 34, 62 + offset); // 90 até 10
      offset += 22;
    }

    myGLCD.print("0", 50, 260);

    myGLCD.setColor(255, 255, 255);

    myGLCD.drawRect(70, 270, 356, 270);       // Eixo X
    myGLCD.drawRect(70, 50, 70, 270);         // Eixo Y

    for (int i = 0; i < 10; i++)
    {
      myGLCD.drawLine(72, (i * 22) + 50, 80, (i * 22) + 50);
    } // Marcador grande
    myGLCD.setColor(190, 190, 190);

    for (int i = 0; i < 10; i++)
    {
      myGLCD.drawLine(72, (i * 22) + 62, 86, (i * 22) + 62);
    } // Marcador pequeno

    for (int i = 0; i < 10; i++)
    {
      myGLCD.drawLine(87, (i * 22) + 50, 356, (i * 22) + 50);
    }// Grade

    myGLCD.setColor(245, 245, 220);          //(255, 255, 255)

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[183])));
    myGLCD.print(buffer, 395, 18);  // tabela_textos[183] = "T.DISSIPADOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[184])));
    myGLCD.print(buffer, 395, 46); // tabela_textos[184] = "TEMP. AGUA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[185])));
    myGLCD.print(buffer, 395, 74); // tabela_textos[185] = "PH DO AQUARIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[186])));
    myGLCD.print(buffer, 395, 102); // tabela_textos[186] =  "PH DO REATOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[187])));
    myGLCD.print(buffer, 395, 130); // tabela_textos[187] = "DENSIDADE:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[188])));
    myGLCD.print(buffer, 395, 158); // tabela_textos[188] = "ORP:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[189])));
    myGLCD.print(buffer, 395, 186); // tabela_textos[189] = "CHILLER:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[190])));
    myGLCD.print(buffer, 395, 214); // tabela_textos[190] = "AQUECEDOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[191])));
    myGLCD.print(buffer, 395, 242); // tabela_textos[191] = "REATOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[192])));
    myGLCD.print(buffer, 395, 270); // tabela_textos[192] = "OZONIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[193])));
    myGLCD.print(buffer, 395, 298); // tabela_textos[193] = "REPOSICAO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[194])));
    myGLCD.print(buffer, 395, 326); // tabela_textos[194] = "NIVEL:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[195])));
    myGLCD.print(buffer, 395, 354); // tabela_textos[195] = "TPA:" // Troca de Água Parcial

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[226])));
    myGLCD.print(buffer, 395, 380); // tabela_textos[226] = "T. AMBIENTE:"

    myGLCD.setColor(0, 255, 0);

    myGLCD.drawCircle(758, 14, 2);                  // Unidade t. dissipador

#ifdef USE_FAHRENHEIT
    myGLCD.print("F", 765, 18);
#else
    myGLCD.print("C", 765, 18);
#endif

    myGLCD.drawCircle(758, 42, 2);                  // Unidade t. água

#ifdef USE_FAHRENHEIT
    myGLCD.print("F", 765, 46);                     // Unidade t. água
#else
    myGLCD.print("C", 765, 46);                     // Unidade t. água
#endif

    myGLCD.print("G/L", 740, 130);                   // Unidade densidade
    myGLCD.print("MV", 747, 158);                    // Unidade ORP

    myGLCD.drawCircle(758, 376, 2);                  // Unidade t. ambiente
    
#ifdef USE_FAHRENHEIT
    myGLCD.print("F", 765, 380);                    // Unidade t. ambiente
#else
    myGLCD.print("C", 765, 380);                    // Unidade t. ambiente
#endif


    myGLCD.setColor(161, 127, 73);
    myGLCD.drawRect(4, 4, 386, 413);                // Desenhar retângulos
    myGLCD.drawRect(386, 4, 796, 413);
    //  myGLCD.drawRect(345, 90, 385, 185); // Atalho
  } // Fim do refreshAll

  if ((refreshAll == true) || (web_timer == true))
  {
    web_timer = false;
    if (temporizador_ativado_e[0] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
      myGLCD.print(buffer, 10, 288); // tabela_textos[31] = "TIMER 1:"
    }
    else
    {
      myGLCD.setColor(245, 245, 220);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
      myGLCD.print(buffer, 10, 288); // tabela_textos[31] = "TIMER 1:"
    }

    if (temporizador_ativado_e[1] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
      myGLCD.print(buffer, 10, 312); // tabela_textos[77] = "TIMER 2:"
    }
    else
    {
      myGLCD.setColor(245, 245, 220);          //(255, 255, 255)
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
      myGLCD.print(buffer, 10, 312); // tabela_textos[77] = "TIMER 2:"
    }

    if (temporizador_ativado_e[2] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
      myGLCD.print(buffer, 10, 336); // tabela_textos[78] = "TIMER 3:"
    }
    else
    {
      myGLCD.setColor(245, 245, 220);          //(255, 255, 255)
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
      myGLCD.print(buffer, 10, 336); // tabela_textos[78] = "TIMER 3:"
    }

    if (temporizador_ativado_e[3] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
      myGLCD.print(buffer, 10, 360); // tabela_textos[79] = "TIMER 4:"
    }
    else
    {
      myGLCD.setColor(245, 245, 220);          //(255, 255, 255)
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
      myGLCD.print(buffer, 10, 360); // tabela_textos[79] = "TIMER 4:"
    }

    if (temporizador_ativado_e[4] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
      myGLCD.print(buffer, 10, 384); // tabela_textos[80] = "TIMER 5:"
    }
    else
    {
      myGLCD.setColor(245, 245, 220);          //(255, 255, 255)
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
      myGLCD.print(buffer, 10, 384); // tabela_textos[80] = "TIMER 5:"
    }
  }

  if ((whiteLed != wled_out) || refreshAll)  // Atualiza gráfico led branco
  {
    whiteLed = wled_out;
    ledLevel = LedToPercent(wled_out);

    drawFillRect(256, 288, 370, 312, 0, 0, 0);  //azzera valori percentuale led
    myGLCD.setColor(cor_canal[0][0], cor_canal[0][1], cor_canal[0][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
    myGLCD.print(buffer, 240, 288); // nome_canal[1] = "BNC"

    offset = map((ledLevel*0.55), 64, 0, 20, 268);

    myGLCD.print(":", 295, 288);
    myGLCD.fillRect(86, offset, 126, 268); //disegna la linea base del led nel grafico
    myGLCD.print(String(ledLevel), 311, 288);
    myGLCD.print("%", 360, 288);

    drawFillRect(86, offset - 1, 126, 48, 0, 0, 0); //disegna il grafico del led
  }
  if ((blueLed != bled_out) || refreshAll)       // Atualiza gráfico led azul
  {
    blueLed = bled_out;
    ledLevel = LedToPercent(bled_out);

    drawFillRect(256, 312, 370, 336, 0, 0, 0);

    myGLCD.setColor(cor_canal[1][0], cor_canal[1][1], cor_canal[1][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
    myGLCD.print(buffer, 240, 312); // nome_canal[2] = "AZU"

    offset = map((ledLevel*0.55), 64, 0, 20, 268);
    
    myGLCD.print(":", 295, 312);
    myGLCD.fillRect(140, offset, 180, 268);
    myGLCD.print(String(ledLevel), 311, 312);
    myGLCD.print("%", 360, 312);

    drawFillRect(140, offset - 1, 180, 48, 0, 0, 0);
  }
  if ((azulroyalLed != rbled_out) || refreshAll)      // Atualiza gráfico led azul royal
  {
    azulroyalLed = rbled_out;
    ledLevel = LedToPercent(rbled_out);

    drawFillRect(256, 336, 370, 360, 0, 0, 0);

    myGLCD.setColor(cor_canal[2][0], cor_canal[2][1], cor_canal[2][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
    myGLCD.print(buffer, 240, 336); // nome_canal[3] = "AZR"

    offset = map((ledLevel*0.55), 64, 0, 20, 268);
    
    myGLCD.print(":", 295, 336);
    myGLCD.fillRect(194, offset, 234, 268);
    myGLCD.print(String(ledLevel), 311, 336);
    myGLCD.print("%", 360, 336);

    drawFillRect(194, offset - 1, 234, 48, 0, 0, 0);
  }
  if ((vermelhoLed != rled_out) || refreshAll)    // Atualiza gráfico led  vermelho
  {
    vermelhoLed = rled_out;
    ledLevel = LedToPercent(rled_out);

    drawFillRect(256, 360, 370, 384, 0, 0, 0); // Apaga potência anterior

    myGLCD.setColor(cor_canal[3][0], cor_canal[3][1], cor_canal[3][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
    myGLCD.print(buffer, 240, 360); // nome_canal[4] = "VER"

   offset = map((ledLevel*0.55), 64, 0, 20, 268);
   
    myGLCD.print(":", 295, 360);
    myGLCD.fillRect(248, offset, 288, 268);
    myGLCD.print(String(ledLevel), 311, 360);
    myGLCD.print("%", 360, 360);

    drawFillRect(248, offset - 1, 288, 48, 0, 0, 0); // Apaga barra anterior
  }
  if ((violetaLed != uvled_out) || refreshAll)      // Atualiza gráfico led violeta
  {
    violetaLed = uvled_out;
    ledLevel = LedToPercent(uvled_out);

    drawFillRect(256, 384, 370, 408, 0, 0, 0); // Apaga potência anterior

    myGLCD.setColor(cor_canal[4][0], cor_canal[4][1], cor_canal[4][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
    myGLCD.print(buffer, 240, 384); // nome_canal[5] = "VIO"

   offset = map((ledLevel*0.55), 64, 0, 20, 268);
   
    myGLCD.print(":", 295, 384);
    myGLCD.fillRect(302, offset, 342, 268);
    myGLCD.print(String(ledLevel), 311, 384);
    myGLCD.print("%", 360, 384);

    drawFillRect(302, offset - 1, 342, 48, 0, 0, 0); // Apaga barra anterior
  }

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(650, 18, 753, 46);                // Apagar temperatura dissipador
  myGLCD.fillRect(650, 46, 753, 74);                // Apagar temperatura agua
  myGLCD.fillRect(650, 74, 790, 102);               // Apagar PH do aquario
  myGLCD.fillRect(650, 102, 790, 130);              // Apagar PH do reator
  myGLCD.fillRect(650, 130, 710, 158);              // Apagar densidade
  myGLCD.fillRect(650, 158, 710, 186);              // Apagar ORP

  myGLCD.fillRect(650, 186, 790, 214);               // Apagar noticia de chiller ligado/desligado
  myGLCD.fillRect(650, 214, 790, 242);              // Apagar noticia de aquecedor ligado/desligado
  myGLCD.fillRect(650, 242, 790, 270);              // Apagar noticia de reator ligado/desligado
  myGLCD.fillRect(650, 270, 790, 278);              // Apagar noticia de ozonio ligado/desligado
  myGLCD.fillRect(650, 278, 790, 306);              // Apagar noticia de reposicao ligado/desligado
  myGLCD.fillRect(650, 306, 790, 334);              // Apagar noticia de nivel normal/anormal
  myGLCD.fillRect(650, 334, 790, 362);              // Apagar noticia de TPA ligado/desligado
  myGLCD.fillRect(650, 362, 730, 408);              // Apaga consumo de energia

  myGLCD.fillRect(135, 288, 195, 312);              // Apagar noticia de Timers 1 ligado/desligado
  myGLCD.fillRect(135, 312, 195, 336);              // Apagar noticia de Timers 2 ligado/desligado
  myGLCD.fillRect(135, 336, 195, 360);              // Apagar noticia de Timers 3 ligado/desligado
  myGLCD.fillRect(135, 360, 195, 384);              // Apagar noticia de Timers 4 ligado/desligado
  myGLCD.fillRect(135, 384, 195, 408);              // Apagar noticia de Timers 5 ligado/desligado


  myGLCD.setColor(0, 255, 0);
  myGLCD.printNumF(tempH, 1, 650, 18);   // Temperatura dissipador
  myGLCD.printNumF(tempC, 1, 650, 46);   // Temperatura da agua
  myGLCD.printNumF(PHA, 1, 650, 74);     // PH aqua
  myGLCD.printNumF(PHR, 1, 650, 102);    // PH reator
  myGLCD.printNumI(DEN, 650, 130);        // Densidade
  myGLCD.printNumI(ORP, 650, 158);       // ORP
  myGLCD.printNumF(tempA, 1, 650, 380);  // Temperatura ambiente

  myGLCD.setColor(255, 0, 0);

  if (bitRead(status_parametros, 2) == true)
  {
    myGLCD.printNumF( tempC, 1, 650, 46);     // Temperatura em vermelho
  }
  if (bitRead(status_parametros, 3) == true)
  {
    myGLCD.printNumF(PHA, 1, 650, 74);       // PH do aquario em vermelho
  }
  if (bitRead(status_parametros, 6) == true)
  {
    myGLCD.printNumF(PHR, 1, 650, 102);       // PH do reator em vermelho
  }
  if (bitRead(status_parametros, 4) == true)
  {
    myGLCD.printNumI(DEN, 650, 130);           // Densidade em vermelho
  }
  if (bitRead(status_parametros_1, 0) == true)
  {
    myGLCD.printNumI(ORP, 650, 158);           // ORP em vermelho
  }
  if (bitRead(status_parametros, 0) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 645, 186);           // Chiller ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 186);          // Chiller desligado
  }
  if (bitRead(status_parametros, 1) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 645, 214);           // Aquecedor ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 214);          // Aquecedor desligado
  }
  if (bitRead(status_parametros, 5) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 645, 242);           // Reator ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 242);          // Reator desligado
  }
  if (bitRead(status_parametros, 7) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 645, 270);           // Ozonio ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 270);          // ozonio desligado
  }
  if (bitRead(Status, 1) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 645, 298);           // Reposição ligada
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 298);          // Reposição desligada
  }
  if (nivel_status1 == true)
  {
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[196])));
    myGLCD.print(buffer, 650, 326);         // Nivel baixo em vermelho // tabela_textos[196] = "BAIXO!"
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[197])));
    myGLCD.print(buffer, 645, 326);          // Nível nornal // tabela_textos[197] = "NORMAL"
  }
  if ((bitRead(tpa_status, 1) == true) && (bitRead(tpa_status, 2) == false))
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 645, 354);           // TPA em andamento
  }
  else if ((bitRead(tpa_status, 1) == false) && (bitRead(tpa_status, 2) == false))
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 354);           // TPA não esta em andamento
  }
  if (bitRead(tpa_status, 2) == true)
  {
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[86])));
    myGLCD.print(buffer, 650, 354);          // Sinaliza falha durante uma TPA // tabela_textos[86] = "FALHA!"
  }
  if (bitRead(temporizador_status, 1) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print(" ON", 135, 288);           // Timer 1 ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(" OFF", 135, 288);          // Timer 1 desligado
  }

  if (bitRead(temporizador_status, 2) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print(" ON", 135, 312);           // Timer 2 ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(" OFF", 135, 312);          // Timer 2 desligado
  }
  if (bitRead(temporizador_status, 3) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print(" ON", 135, 336);           // Timer 3 ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(" OFF", 135, 336);          // Timer 3 desligado
  }
  if (bitRead(temporizador_status, 4) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print(" ON", 135, 360);           // Timer 4 ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(" OFF", 135, 360);          // Timer 4 desligado
  }
  if (bitRead(temporizador_status, 5) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print(" ON", 135, 384);           // Timer 5 ligado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(" OFF", 135, 384);          // Timer 5 desligado
  }
  if (temperatura_alta == true)
  {
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[236])));// "TEMPERATURA ALTA!"
    myGLCD.print(buffer, 116, 155);          // Alerta de temperatura alta para os LEDS.
  }
  if (temperatura_baixou == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[237]))); // "TEMP. BAIXOU!"
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(buffer, 116, 155);          // Alerta de que a temperatura esteve alta para os LEDS.
  }
}
#endif


  




