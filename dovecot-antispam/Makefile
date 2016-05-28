# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:37 asau Exp $

DISTNAME=	dovecot-antispam-1.3-pre1
PKGNAME=	dovecot-antispam-1.2.90.1
CATEGORIES=	mail
MASTER_SITES=	http://johannes.sipsolutions.net/download/dovecot-antispam/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://johannes.sipsolutions.net/Projects/dovecot-antispam
COMMENT=	Antispam plugin for Dovecot

LICENSE=	gnu-gpl-v2


USE_TOOLS+=		gmake
#MAKE_DIRS+=		lib/dovecot/imap

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	post-patch
SUBST_FILES.pkgsrc=	defconfig
SUBST_SED.pkgsrc=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.pkgsrc+=	-e "s|@ROOT_USER@|${ROOT_USER}|g"
SUBST_SED.pkgsrc+=	-e "s|@ROOT_GROUP@|${ROOT_GROUP}|g"

pre-configure:
	cp ${WRKSRC}/defconfig ${WRKSRC}/.config

.include "../../mail/dovecot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
