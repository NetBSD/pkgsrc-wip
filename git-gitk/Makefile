# $NetBSD: Makefile,v 1.9 2025/01/13 14:24:44 adam Exp $

PKGNAME=	git-gitk-${GIT_VERSION}
PKGREVISION=	1
COMMENT=	GIT Tree History Storage Tool (gitk)

CONFLICTS+=	git-base<1.7.12nb1
CONFLICTS+=	scmgit-gitk-[0-9]*
SUPERSEDES+=	scmgit-gitk-[0-9]*

DEPENDS+=	git-base>=1.7.12nb1:../../devel/git-base

BUILD_DIRS=		git-gui gitk-git
INSTALL_DIRS=		${BUILD_DIRS}
MAKE_ENV+=		prefix=${PREFIX}
TK90WISH=		${PREFIX}/${TK90_SUBDIR}/bin/wish
MAKE_ENV+=		TCLTK_PATH=${TK90WISH:Q}

CONFIGURE_ARGS+=	--with-tcltk=${TK90WISH:Q}

INSTALLATION_DIRS+=	bin

# not substituted even when using --with-tcltk and TCLTK_PATH
SUBST_CLASSES+=		wish
SUBST_FILES.wish+=	git-gui/git-gui--askpass
SUBST_SED.wish+=	-e "s,exec wish,exec ${TK90WISH:Q},"
SUBST_SED.wish+=	-e "s,exec 'wish',exec ${TK90WISH:Q},"
SUBST_STAGE.wish=	post-configure
SUBST_MESSAGE.wish=	Fixing path to wish binary.

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
ALL_ENV+=		gitexecdir=${PREFIX:Q}/libexec/git-core	# XXX
CONFIGURE_ENV.NetBSD+=	ac_cv_iconv_omits_bom=no
CONFIGURE_ENV.NetBSD+=	ac_cv_fread_reads_directories=yes
CONFIGURE_ENV.NetBSD+=	ac_cv_snprintf_returns_bogus=no
.endif

.include "../../devel/git/Makefile.common"

# does not link against it, but we need TK90_SUBDIR
.include "../../wip/tk90/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
