from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import random

# Открываем браузер Chrome
driver = webdriver.Chrome()

lan = [55.0120340871232, 55.01414706654303, 55.01293177172159, 55.01380181607795, 55.01484998428666]
lon = [82.95055087051928, 82.94882876286135, 82.95034614443408, 82.9524777042624, 82.9486522681325]

#ZAGS
#55.0120340871232, 82.95055087051928
#random point
#55.01414706654303, 82.94882876286135
#SibSUTIS
#55.01293177172159, 82.95034614443408
#Alcopolis
#55.01380181607795, 82.9524777042624
#random point 
# 82.9486522681325

for i in range (0, len(lan)):
    latitude = str(lan[i])
    longitude = str(lon[i])

    # Формируем URL для запроса к Open ElevationAPI
    # https://api.open-elevation.com/api/v1/lookup?locations=41.161758,-8.583933
    url = f'https://api.open-elevation.com/api/v1/lookup?locations={latitude},{longitude}'

    # Переходим на страницу Open Elevation API
    driver.get(url)

    # Ждем, пока элемент станет доступным на странице
    wait = WebDriverWait(driver, 10)
    element = wait.until(EC.presence_of_element_located((By.XPATH, '//pre')))

    # Получаем высоту из элемента
    elevation = element.text
    elevation = (elevation.split(',')[2].split(':')[1].split('}')[0])

    # Выводим результат
    print(f'Высота над уровнем моря в точке ({latitude}, {longitude}): {elevation} метров')
driver.quit()