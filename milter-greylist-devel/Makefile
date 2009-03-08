# $NetBSD: Makefile,v 1.4 2009/03/08 00:23:49 pettai Exp $

DISTNAME=	milter-greylist-4.1.12
PKGNAME=	milter-greylist-devel-4.1.12
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

OWNER=		pettai@nordu.net
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail devel snapshot

PKG_DESTDIR_SUPPORT=	user-destdir

# yacc rule moving to y.tab.c and renaming
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-user=smmsp

BUILD_DEFS+=		IPV6_READY

BUILD_TARGET=		milter-greylist

PKG_GROUPS=		smmsp
PKG_USERS=		smmsp:smmsp
PKG_GECOS.smmsp=	Sendmail Message Submission Program

RCD_SCRIPTS=	milter-greylist

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
	  ${DESTDIR}${PREFIX}/share/examples/milter-greylist

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
