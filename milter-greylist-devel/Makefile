# $NetBSD: Makefile,v 1.6 2012/10/03 15:09:55 asau Exp $

DISTNAME=	milter-greylist-${VERSION}
PKGNAME=	milter-greylist-devel-${VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

OWNER=		pettai@nordu.net
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail devel snapshot

VERSION=	4.3.3

# yacc rule moving to y.tab.c and renaming
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-user=smmsp

BUILD_DEFS+=		IPV6_READY

BUILD_TARGET=		milter-greylist

PKG_GROUPS=		smmsp
PKG_USERS=		smmsp:smmsp
PKG_GECOS.smmsp=	Sendmail Message Submission Program

INSTALLATION_DIRS=	${DESTDIR}${PREFIX}/share/doc/milter-greylist
INSTALLATION_DIRS+=	${DESTDIR}${PREFIX}/share/examples/milter-greylist

RCD_SCRIPTS=	milter-greylist

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
	  ${DESTDIR}${PREFIX}/share/examples/milter-greylist

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
