# $NetBSD: Makefile,v 1.4 2012/09/24 16:56:35 asau Exp $
#

PKG_DESTDIR_SUPPORT=	none

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
SUBST_SED.mailer=	-e s,/bin/mail,${MAIL_CMD},
SUBST_MESSAGE.mailer=	Fixing mail command path.

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
