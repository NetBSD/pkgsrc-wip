# $NetBSD: Makefile,v 1.1 2014/05/16 15:19:19 hfath Exp $

INETDXTRA_VERSION=	20130516
DISTNAME=		inetdxtra-${INETDXTRA_VERSION}_src
PKGNAME=		${DISTNAME:S/_src//}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=inetdxtra/}

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://inetdxtra.sourceforge.net/
COMMENT=		Collection of inetd based servers

LICENSE=		gnu-gpl-v2

PKG_SYSCONFSUBDIR=	inetdxtra
CFLAGS+=		-DSYSCONFDIR=\"${PKG_SYSCONFDIR}\"
CFLAGS+=		-DONELOG -DNORELATIVE -DCGI -DUPDATEPS

WRKSRC=			${WRKDIR}/inetdxtra
LIBEXECDIR=		${DESTDIR}${PREFIX}/libexec/inetdxtra
DOCDIR=			${DESTDIR}${PREFIX}/share/doc/inetdxtra
EGDIR=			${DESTDIR}${PREFIX}/share/examples/inetdxtra

# TODOs
#
# Take care of example preference files

do-install:
	${MKDIR} ${LIBEXECDIR}
	${MKDIR} ${DOCDIR}
	${MKDIR} ${EGDIR}
.for pp in ctcs dhcp dns jabberd mvp proxy smtp www
	${INSTALL_PROGRAM} ${WRKSRC}/in.${pp}/in.${pp} ${LIBEXECDIR}
	${INSTALL_DATA} ${WRKSRC}/in.${pp}/README ${DOCDIR}/README.${pp}
.endfor
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/inetd.conf.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/in.dhcp/in.dhcp.conf.sample ${EGDIR}

.include "../../mk/bsd.pkg.mk"
