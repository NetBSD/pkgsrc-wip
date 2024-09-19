# $NetBSD: Makefile,v 1.8 2014/06/22 19:53:41 thomasklausner Exp $

.include "../../wip/ap2-evasive/Makefile.common"

PKGNAME=		ap2-evasive-1.10.1
PKGREVISION=		3

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

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
