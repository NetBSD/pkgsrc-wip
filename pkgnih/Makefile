# $NetBSD: Makefile,v 1.8 2011/03/08 14:22:18 cheusov Exp $

DISTNAME=	pkgnih-0.5
PKGREVISION=	2
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/pkgnih/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc
LICENSE=	2-clause-bsd

DEPENDS+=		pkg_summary-utils>=0.53beta1:../../wip/pkg_summary-utils
DEPENDS+=		pkg_status>=0.14:../../wip/pkg_status
DEPENDS+=		digest-[0-9]*:../../pkgtools/digest
DEPENDS+=		pkg_install>=20100915:../../pkgtools/pkg_install

BUILD_DEPENDS+=		mk-configure>=0.21.0:../../devel/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

EGDIR=			${PREFIX}/share/examples/nih

CONF_FILES=		${EGDIR}/nih.conf \
			${PKG_SYSCONFDIR}/nih/config

MAKE_DIRS+=		${PKG_SYSCONFDIR}/nih

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		EGDIR=${EGDIR}
MAKE_ENV+=		DOCDIR=${PREFIX}/share/doc/pkgnih

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		mkcmake
