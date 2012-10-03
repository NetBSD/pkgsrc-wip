# $NetBSD: Makefile,v 1.12 2012/10/03 18:15:32 asau Exp $

DISTNAME=	pkgnih-999
PKGNAME=	nih-999
CATEGORIES=	pkgtools

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc

LICENSE=	2-clause-bsd

GIT_REPOSITORIES=	pkgnih
GIT_REPO.pkgnih=	git://github.com/cheusov/pkgnih.git
.include "../../wip/mk/git-package.mk"

DEPENDS+=	pkg_summary-utils>=0.56.0:../../pkgtools/pkg_summary-utils
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest
DEPENDS+=	pkg_install>=20100915:../../pkgtools/pkg_install

BUILD_DEPENDS+=		mk-configure>=0.21.0:../../devel/mk-configure

CONFLICTS=		pkg_status-[0-9]*
SUPERSEDES=		pkgnih-[0-9]*

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
MAKE_ENV+=		VERSION=${_GIT_PKGVERSION:S/.//}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD || ${OPSYS} == FreeBSD || ${OPSYS} == OpenBSD || \
    ${OPSYS} == DragonFly || ${OPSYS} == MirBSD
FTP_CMD=/usr/bin/ftp
.else
FTP_CMD=${PREFIX}/bin/ftp
DEPENDS+=	tnftp-[0-9]*:../../net/tnftp
.endif

MAKE_ENV+= FTP=${FTP_CMD:Q}

.if ${OPSYS} =="SunOS" && empty(OS_VERSION:M5.11*)
REPLACE_SH+=	nih/nih.in nih/pkg_status.in
.endif

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
