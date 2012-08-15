# $NetBSD: Makefile,v 1.1 2012/08/15 11:10:16 fhajny Exp $
#

DISTNAME=	stud-0
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/bumptech/stud
COMMENT=	Scalable TLS Unwrapping Daemon
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GIT_REPOSITORIES=	stud
GIT_REPO.stud=		git://github.com/bumptech/stud.git

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/${PKGBASE}
INSTALLATION_DIRS+=	bin

.include "../../wip/mk/git-package.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
