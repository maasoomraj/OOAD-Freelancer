import smtplib
from sys import argv

try:
    s = smtplib.SMTP('smtp.gmail.com', 587)
    s.starttls()
    SENDER = "sender_email" # Enter sender email id
    PASSWORD = "pass"  # Enter password
    s.login(SENDER, PASSWORD) 
    SUBJECT = "Forgot password"
    TEXT = "Your password is " + argv[2]
    message = 'Subject: {}\n\n{}'.format(SUBJECT, TEXT)
    s.sendmail(SENDER, argv[1], message) 
    s.quit() 
except:
    print ('Something went wrong...')

