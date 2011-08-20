# $NetBSD: Makefile,v 1.3 2011/08/20 15:53:33 cheusov Exp $

DISTNAME=	pkgnih-999
PKGNAME=	nih-999
CATEGORIES=	pkgtools

MAINTAINER=	vle@gmx.net
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc

LICENSE=	2-clause-bsd

GIT_MODULE=		pkgnih
GIT_REPOSITORIES=	master
GIT_REPO.master=	git://github.com/cheusov/pkgnih.git
.include "../../wip/mk/git-package.mk"

DEPENDS+=		pkg_summary-utils>=0.55alpha2:../../pkgtools/pkg_summary-utils

DEPENDS+=		digest-[0-9]*:../../pkgtools/digest
DEPENDS+=		pkg_install>=20100915:../../pkgtools/pkg_install

BUILD_DEPENDS+=		mk-configure>=0.21.0:../../devel/mk-configure
SUPERSEDES=		pkgnih-[0-9]*

CONFLICTS=		pkg_status-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

WRKSRC=			${WRKDIR}/pkgnih
EGDIR=			${PREFIX}/share/examples/nih

CONF_FILES=		${EGDIR}/nih.conf \
			${PKG_SYSCONFDIR}/nih/config

MAKE_DIRS+=		${PKG_SYSCONFDIR}/nih

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	nih/pkg_update_plan.in nih/cmp2hr.in

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		VERSION=${_GIT_TODAY:S/-//g}

MAKE_PROGRAM=		mkcmake

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
