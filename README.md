# Homeworks-Labs

Коллекция заголовочных файлов для лабораторных работ

# Как это установить ?

  * Идём и качаем git [по этой ссылке](https://git-scm.com/download/win)
  * Устанавливаем, следуя инструкциям
  * Открываем терминал, пишем ssh-keygen.
    Видим вот такое, запоминаем путь, подчёркнутый красным
    
    ![terminal1](https://github.com/IgorKreknin/Pictures/blob/master/1.PNG)
    
  * Много раз жмём Enter (Мы не меняем место хранения ключа и нам не нужен пароль) и видим такое:
    
    ![terminal2](https://github.com/IgorKreknin/Pictures/blob/master/2.PNG)
    
    Наш ключ создан и лежит по пути, который мы запомнили в предыдущем пункте
  * Открываем папку с нашим ключём. Нас интересует файл с расширением .pub
  
    ![filemanager1](https://github.com/IgorKreknin/Pictures/blob/master/3.PNG)
    
    Открываем его блокнотом или другим текстовым редактором и копируем содержимое
  * Дальше есть два пути:
  
    I. Скинуть ключ Игорю и он сделает этот шаг за вас (Для ленивых)
    
    II. Авторизоваться на гите (login: B18-504, password: b185042018) и выполнить следующие действия:
    
    Идём в менюшку (в правом верхнем углу), выбираем пункт Settings
    
    ![web1](https://github.com/IgorKreknin/Pictures/blob/master/4.PNG)
    
    Затем пункт SSH and GPG keys и жмём кнопку New SSH key
    
    ![web2](https://github.com/IgorKreknin/Pictures/blob/master/5.PNG)
    
    В появившееся окно пишем ваш ключ (можно ctrl + V) и жмём кнопку Add SSH key
    
    ![web3](https://github.com/IgorKreknin/Pictures/blob/master/6.PNG)
  * Теперь можно склонировать себе репозиторий
  
    Идём на страницу репозитория, жмём кнопку Clone or download и копируем ссылку в выпадающем окне (Если вместо Use HTTPS у вас Use SSH, то жмём Use SSH)
    
    ![web4](https://github.com/IgorKreknin/Pictures/blob/master/7.PNG)
    
    Снова открываем терминал и пишем git clone "скопированный ключ"
    
    ![terminal2](https://github.com/IgorKreknin/Pictures/blob/master/8.PNG)
    
  * Мы создали локальный репозиторий гита. Папка с файлами лежит в той папке, откуда была запущена команда git clone (Можно найти через поиск файлов. Называется Homeworks-Labs)
  
# Как этим пользоваться ?
  
  * Идём в папку, в которой лежит наш репозиторий
  
    ![files](https://github.com/IgorKreknin/Pictures/blob/master/9.PNG)
    
  * Создаём новую ветку и переключаемся на неё (Название ветки - ваша фамилия)
  
    Пишем git checkout -b "Ваша фамилия"
    
    ![terminal1](https://github.com/IgorKreknin/Pictures/blob/master/10.PNG)
    
  * Коммитим изменения и пушим (Перед коммитом пишите пожалуйста git status и смотрите на какой вы ветке. Не очент приятно будет, если вы перетрёте чужие файлы)
   
