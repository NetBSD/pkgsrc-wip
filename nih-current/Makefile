# $NetBSD: Makefile,v 1.21 2015/03/01 14:59:36 cheusov Exp $

DISTNAME=	pkg${PKGNAME}
PKGREVISION=
PKGNAME=	nih-${_GIT_PKGVERSION}
CATEGORIES=	pkgtools

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc
LICENSE=	2-clause-bsd

GIT_REPOSITORIES=	pkgnih
GIT_REPO.pkgnih=	https://github.com/cheusov/pkgnih.git
#GIT_BRANCH.pkgnih=	develop

.include "../../wip/mk/git-package.mk"

DEPENDS+=	pkg_summary-utils>=0.69.0:../../pkgtools/pkg_summary-utils
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest
DEPENDS+=	pkg_install>=20100915:../../pkgtools/pkg_install

TOOL_DEPENDS+=		mk-configure>=0.21.0:../../devel/mk-configure

CONFLICTS=		pkg_status-[0-9]*
SUPERSEDES=		pkgnih-[0-9]*

BUILD_TARGET=		all all-doc
INSTALL_TARGET=	install install-doc

WRKSRC=		${WRKDIR}/pkgnih
EGDIR=			${PREFIX}/share/examples/nih

CONF_FILES=		${EGDIR}/nih.conf \
			${PKG_SYSCONFDIR}/nih.conf

MAKE_DIRS+=		${VARBASE}/cache/nih/summary ${VARBASE}/cache/nih/src_summary \
   ${VARBASE}/cache/nih/packages ${VARBASE}/cache/nih/history

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	nih/pkg_update_plan.in nih/cmp2hr.in \
			nih/pkg_create_fake.in nih/analyse_conflicts.in

MAKE_ENV+=		VERSION=${_GIT_PKGVERSION}
MAKE_ENV+=		PKG_DBDIR=${PKG_DBDIR}
MAKE_ENV+=		VARDIR=${VARBASE}
MAKE_ENV+=		REAL_ROOT_USER=${REAL_ROOT_USER}
MAKE_ENV+=		REAL_ROOT_GROUP=${REAL_ROOT_GROUP}
MAKE_ENV+=		PKGSRCDIR=${PKGSRCDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD || ${OPSYS} == FreeBSD || ${OPSYS} == OpenBSD || \
    ${OPSYS} == DragonFly || ${OPSYS} == MirBSD
FTP_CMD=	/usr/bin/ftp
.else
FTP_CMD=	${PREFIX}/bin/ftp
DEPENDS+=	tnftp-[0-9]*:../../net/tnftp
.endif

MAKE_ENV+=	FTP=${FTP_CMD:Q} PKG_TOOLS_BIN=${PKG_TOOLS_BIN}

.if ${OPSYS} =="SunOS" #&& empty(OS_VERSION:M5.11*)
REPLACE_SH+=	nih/nih.in nih/pkg_status.in
.endif

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
