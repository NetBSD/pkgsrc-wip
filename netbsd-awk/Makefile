# $NetBSD: Makefile,v 1.17 2011/10/09 10:05:44 cheusov Exp $
#

DISTNAME=	netbsd-awk-20110509
CATEGORIES=	lang sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://cvsweb.NetBSD.org/bsdweb.cgi/src/external/historical/nawk/dist/
COMMENT=		NetBSD version of AWK
#LICENSE=		mit/bsd?

BUILD_DEPENDS+=		mk-configure>0.19.0:../../devel/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		yacc lex

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

post-patch:
	set -e; \
	sed -e 's|awk|nbawk|g' ${WRKSRC}/awk.1 > ${WRKSRC}/nbawk.1; \
	cp ${FILESDIR}/*.c ${FILESDIR}/*.h ${FILESDIR}/Makefile ${WRKSRC}/

MAKE_PROGRAM=		mkcmake

.include "../../mk/bsd.pkg.mk"
