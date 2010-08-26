# $NetBSD: Makefile,v 1.13 2010/08/26 20:05:28 cheusov Exp $
#

DISTNAME=	mawk-1.3.4-20100625
PKGNAME=	${DISTNAME:S/-20/.20/:S/mawk/mawk-uxre/}
CATEGORIES=	lang
MASTER_SITES=	ftp://invisible-island.net/mawk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	vle@gmx.net
COMMENT=	AWK clone by Mike Brennan

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin

TEST_TARGET=		mawk_test fpe_test

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-builtin-regex

MAKEFLAGS+=		LIBS=-luxre\ -lm

MAKE_JOBS_SAFE=		no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mawk ${DESTDIR}${PREFIX}/bin/mawk-uxre
	${INSTALL_MAN} ${WRKSRC}/man/mawk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mawk-uxre.1

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
