# $NetBSD: Makefile,v 1.2 2006/01/17 09:13:36 rillig Exp $
#

.include "../../wip/ap-evasive/Makefile.common"

PKGNAME=		ap2-evasive-1.10.1
PKG_APACHE_ACCEPTED=	apache2

APACHE_MODULE=		yes
APACHE_MODULE_NAME=	mod_evasive20.so
APACHE_MODULE_SRC=	mod_evasive20.c

USE_TOOLS+=		mail

SUBST_CLASSES+=		mailer
SUBST_STAGE.mailer=	post-patch
SUBST_FILES.mailer=	mod_evasive.c
SUBST_SED.mailer=	-e s,/bin/mail,${MAIL_CMD},
SUBST_MESSAGE.mailer=	Fixing mail command path.

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
