From: "DrWeb-DAEMON" $FILTER_MAIL$
To: $SENDER$
Subject: Undelivered mail: $SUBJECT$
Content-Type: multipart/mixed;
 boundary="001-DrWeb-MailFilter-Notification"
MIME-Version: 1.0

--001-DrWeb-MailFilter-Notification
Content-Type: text/plain; charset=us-ascii

Dear User,

the message with following attributes has not been delivered, 
because contains an object which violates archive restrictions 
and cannot be checked by antivirus filter. 
Relaying such messages is blocked by administrator.

Sender = $SENDER$
Recipients = $RCPTS$
Subject = $SUBJECT$
Message-ID = $MSGID$

Antivirus filter report:
--- Dr.Web report ---
Dr.Web detailed report:
$DAEMON_REPORT$
Dr.Web scanning statistic:
$SCAN_STAT$
--- Dr.Web report ---

Please contact $POSTMASTER$

---
   Antivirus service provided by Dr.Web(R) Daemon for Unix
   (http://www.drweb.ru, http://www.dials.ru/english)

--001-DrWeb-MailFilter-Notification
Content-Type: text/plain

$FULLHEADERS$
--001-DrWeb-MailFilter-Notification--
