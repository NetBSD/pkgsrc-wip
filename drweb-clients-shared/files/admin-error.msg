From: "DrWeb-DAEMON" $FILTER_MAIL$
To: "AV-Administrator" $POSTMASTER$
Subject: The antivirus software failure
Content-Type: multipart/mixed;
 boundary="001-DrWeb-MailFilter-Notification"
MIME-Version: 1.0

--001-DrWeb-MailFilter-Notification
Content-Type: text/plain; charset=us-ascii

Dear Postmaster,

the message with following attributes has not been delivered,
because contains an object which cannot be checked by antivirus.

Sender = $SENDER$
Recipients = $RCPTS$
Subject = $SUBJECT$
Message-ID = $MSGID$

--- Dr.Web report ---
Dr.Web detailed report:
$DAEMON_REPORT$
--- Dr.Web report ---

--001-DrWeb-MailFilter-Notification
Content-Type: text/plain

$FULLHEADERS$
--001-DrWeb-MailFilter-Notification--
