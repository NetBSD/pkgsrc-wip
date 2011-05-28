# $NetBSD: Makefile,v 1.14 2011/05/28 15:54:14 cheusov Exp $
#

DISTNAME=	netbsd-awk-20110509
CATEGORIES=	lang sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://cvsweb.netbsd.org/bsdweb.cgi/src/external/historical/nawk/dist/
COMMENT=		NetBSD version of AWK
# LICENSE=		modified-bsd

BUILD_DEPENDS=		mk-configure>0.19.0:../../devel/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		yacc lex

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

post-patch:
	set -e; \
	sed -e 's|awk|nbawk|g' ${WRKSRC}/awk.1 > ${WRKSRC}/nbawk.1; \
	cp ${FILESDIR}/* ${WRKSRC}/

MAKE_PROGRAM=		mkcmake

.include "../../mk/bsd.pkg.mk"
