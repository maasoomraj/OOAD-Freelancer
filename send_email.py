import smtplib
from sys import argv

try:
    s = smtplib.SMTP('smtp.gmail.com', 587)
    s.starttls()
    s.login("sender_email", "pass") 
    message = "Your password is " + argv[2]
    s.sendmail("sender_email", argv[1], message) 
    s.quit() 
except:
    print ('Something went wrong...')

