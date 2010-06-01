# $NetBSD: Makefile,v 1.2 2010/06/01 06:14:49 obache Exp $
#

DISTNAME=	se${VERSION:tl:S/.//g}
PKGNAME=	slashem-${VERSION}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slashem/}

MAINTAINER=	lifanov@mail.lifanov.com
HOMEPAGE=	http://slashem.sourceforge.net/
COMMENT=	Slash'EM is a Nethack variant with more stuff
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes

CONFIGURE_SCRIPT=	setup.sh
CONFIGURE_DIRS=		sys/unix
BUILD_DIRS=		.

VERSION=	0.0.7E7F3

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	post-configure
SUBST_FILES.dirs=	Makefile
SUBST_SED.dirs=		-e 's|/usr|${PREFIX}|'
SUBST_SED.dirs+=	-e 's|/local||'

.include "../../mk/bsd.pkg.mk"
