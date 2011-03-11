# $NetBSD: Makefile,v 1.15 2011/03/11 21:17:08 cheusov Exp $

DISTNAME=	pkgnih-999
CATEGORIES=	pkgtools

MAINTAINER=	vle@gmx.net
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc

LICENSE=	2-clause-bsd

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://github.com/cheusov/pkgnih.git
.include "../../wip/mk/git-package.mk"

DEPENDS+=		pkg_summary-utils>=0.53beta3:../../wip/pkg_summary-utils
DEPENDS+=		pkg_status>=0.14:../../wip/pkg_status
DEPENDS+=		digest-[0-9]*:../../pkgtools/digest
DEPENDS+=		pkg_install>=20100915:../../pkgtools/pkg_install

BUILD_DEPENDS+=		mk-configure>=0.21.0:../../devel/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

WRKSRC=			${WRKDIR}/pkgnih
EGDIR=			${PREFIX}/share/examples/nih

CONF_FILES=		${EGDIR}/nih.conf \
			${PKG_SYSCONFDIR}/nih/config

MAKE_DIRS+=		${PKG_SYSCONFDIR}/nih

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		EGDIR=${EGDIR}
MAKE_ENV+=		DOCDIR=${PREFIX}/share/doc/pkgnih

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		mkcmake
