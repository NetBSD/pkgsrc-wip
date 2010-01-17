# $NetBSD: Makefile,v 1.6 2010/01/17 12:03:23 thomasklausner Exp $
#

.include "../../wip/ap-evasive/Makefile.common"

PKGNAME=		ap2-evasive-1.10.1
PKGREVISION=		3
PKG_APACHE_ACCEPTED=	apache2

APACHE_MODULE=		yes
APACHE_MODULE_NAME=	${DISTNAME:C|_[^_]*$||}20.so
APACHE_MODULE_SRC=	${DISTNAME:C|_[^_]*$||}20.c
APACHE_MODULE_LA=	${DISTNAME:C|_[^_]*$||}20.la

USE_TOOLS+=		mail

SUBST_CLASSES+=		mailer
SUBST_STAGE.mailer=	post-patch
SUBST_FILES.mailer=	mod_evasive.c
SUBST_SED.mailer=	-e s,/bin/mail,${MAIL_CMD},
SUBST_MESSAGE.mailer=	Fixing mail command path.

do-build:
	cd ${WRKSRC} && ${APXS} -c -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_SRC}

do-install:
	cd ${WRKSRC} && ${APXS} -i -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_LA}

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
