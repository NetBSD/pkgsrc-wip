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
because contains an infected object.

Sender = $SENDER$ (may be forged)
Recipients = $RCPTS$ 
Subject = $SUBJECT$
Message-ID = $MSGID$

Antivirus filter report:
--- Dr.Web report ---
Following virus(es) has been found:
$VIRUS_LIST$
Dr.Web detailed report:
$DAEMON_REPORT$
Dr.Web scanning statistic:
$SCAN_STAT$
--- Dr.Web report ---

The original message was stored in archive record named: 
$ARCHIVE_RECORD$ 
In order to receive the original message, please send request to 
$POSTMASTER$, referring to the archive record 
name given above.

---
   Antivirus service provided by Dr.Web(R) Daemon for Unix
   (http://www.drweb.ru, http://www.dials.ru/english)

--001-DrWeb-MailFilter-Notification
Content-Type: text/plain

$FULLHEADERS$
--001-DrWeb-MailFilter-Notification--
