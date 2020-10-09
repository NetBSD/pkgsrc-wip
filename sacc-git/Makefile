# $NetBSD: Makefile,v 1.2 2018/02/28 16:32:56 leot Exp $

DISTNAME=	sacc-1.02
CATEGORIES=	net
MASTER_SITES=	ftp://bitreich.org/releases/sacc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/sacc
COMMENT=	Console gopher client
LICENSE=	isc

GIT_REPOSITORIES=	sacc
GIT_REPO.sacc=		git://bitreich.org/sacc/
WRKSRC=			${WRKDIR}/sacc

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}/man1"
MAKE_FLAGS+=	LIBS=${BUILDLINK_LDADD.terminfo:Q}

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# strcasestr, asprintf
LDFLAGS.SunOS+=	-lsocket -lnsl

USE_LANGUAGES=	c99

.include "../../mk/terminfo.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
