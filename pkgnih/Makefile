# $NetBSD: Makefile,v 1.15 2011/04/05 11:12:55 cheusov Exp $

DISTNAME=	pkgnih-0.6.4
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/pkgnih/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc
LICENSE=	2-clause-bsd

DEPENDS+=	pkg_summary-utils>=0.53.1:../../wip/pkg_summary-utils
DEPENDS+=	pkg_status>=0.14:../../wip/pkg_status
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest
DEPENDS+=	pkg_install>=20100915:../../pkgtools/pkg_install

BUILD_DEPENDS+=		mk-configure>=0.21.0:../../devel/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

EGDIR=			${PREFIX}/share/examples/nih

CONF_FILES=		${EGDIR}/nih.conf \
			${PKG_SYSCONFDIR}/nih/config

MAKE_DIRS+=		${PKG_SYSCONFDIR}/nih

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		mkcmake
