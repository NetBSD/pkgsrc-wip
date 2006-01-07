# $NetBSD: Makefile,v 1.1.1.1 2006/01/07 01:10:00 cetrox Exp $
#

.include "Makefile.common"

PKGNAME=		ap-evasive-1.10.1
PKG_APACHE_ACCEPTED=	apache13

APACHE_MODULE=		yes
APACHE_MODULE_NAME=	mod_evasive.so
APACHE_MODULE_SRC=	mod_evasive.c

USE_TOOLS+=		mail

SUBST_CLASSES+=		mailer
SUBST_STAGE.mailer=	post-patch
SUBST_FILES.mailer=	mod_evasive.c
SUBST_SED.mailer=	-e s,/usr/bin/mail,${MAIL_CMD},
SUBST_MESSAGE.mailer=	"Fixing mail command path."

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
