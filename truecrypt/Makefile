# $NetBSD: Makefile,v 1.3 2010/04/14 04:00:32 othyro Exp $
#

DISTNAME=	TrueCrypt%206.3a%20Source
PKGNAME=	truecrypt-6.3a
CATEGORIES=	security

DOWNLOAD=	http://www.truecrypt.org/downloads2
MAINTAINER=	schaecsn@gmx.net
HOMEPAGE=	http://www.truecrypt.org/
COMMENT=	Filesystem encryption package
LICENSE=	truecrypt-license
LICENSE_FILE=	truecrypt-license

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/truecrypt-6.3a-source

USE_TOOLS+=     gmake pkg-config
NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++
GCC_REQD=	4.0

ONLY_FOR_PLATFORM= Linux-*-*  # maybe: Darwin-*-*

RESTRICTED=	Unclear license
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

FETCH_MESSAGE =	" The file ${DISTNAME}${EXTRACT_SUFX} must be fetched"
FETCH_MESSAGE+=	" from ${DOWNLOAD}"
FETCH_MESSAGE+=	" into ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"
FETCH_MESSAGE+=	""
FETCH_MESSAGE+=	" Read and accept the license. Then chose \"Mac OS X / Linux (.tar.gz)\""
FETCH_MESSAGE+=	" and click download."

BUILD_TARGET=
MAKE_ENV+=	PKCS11=1

INSTALLATION_DIRS+= bin

post-fetch:
	if [ ! -x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then	\
		${CHMOD} +x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX};	\
	fi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Main/truecrypt ${DESTDIR}${PREFIX}/bin/

.include "../../filesystems/fuse/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
