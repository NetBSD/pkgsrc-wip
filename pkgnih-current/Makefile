# $NetBSD: Makefile,v 1.6 2011/01/02 21:49:05 cheusov Exp $

DISTNAME=	pkgnih-0.0
CATEGORIES=	pkgtools

MAINTAINER=	vle@gmx.net
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc

LICENSE=	2-clause-bsd

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://github.com/cheusov/pkgnih.git
.include "../../wip/mk/git-package.mk"

DEPENDS+=		pkg_summary-utils>=0.50beta8:../../wip/pkg_summary-utils
DEPENDS+=		pkg_status>=0.12:../../wip/pkg_status
DEPENDS+=		digest-[0-9]*:../../pkgtools/digest
BUILD_DEPENDS+=		mk-configure>=0.21.0:../../wip/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/pkgnih
EGDIR=			${PREFIX}/share/examples/nih

CONF_FILES=		${EGDIR}/nih.conf \
			${PKG_SYSCONFDIR}/nih/config

MAKE_DIRS+=		${PKG_SYSCONFDIR}/nih

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		EGDIR=${EGDIR}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		mkcmake
