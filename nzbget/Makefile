# $NetBSD: Makefile,v 1.17 2012/10/03 18:15:33 asau Exp $
#
VERSION=		17.1
PKGNAME=		nzbget-${VERSION}
DISTNAME=		${PKGNAME}
GITHUB_TAG=		v${VERSION}
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_GITHUB:=nzbget/}

MAINTAINER=		amoibos@gmail.com
HOMEPAGE=		http://nzbget.sourceforge.net/
COMMENT=		Binary newsreader with NZB support
LICENSE=		gnu-gpl-v2

#USE_TOOLS+=		gmake
#USE_TOOLS+=		autoconf
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CHECK_PORTABILITY_SKIP=	Makefile.am configure

CONFIGURE_ARGS+=	--with-libcurses-includes=${DESTDIR}${PREFIX}/include \
			--with-libcurses-libraries=${DESTDIR}${PREFIX}/lib

INSTALLATION_DIRS=	share/examples/nzbget

EXAMPLES=		nzbget.conf

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	scripts/EMail.py scripts/Logger.py
SUBST_SED.python=	-e 's,/usr/bin/env python,${PYTHONBIN},'

#pre-configure:
#	cd ${WRKSRC} && autoconf

post-install:
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${INSTALLATION_DIRS}
.endfor

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
