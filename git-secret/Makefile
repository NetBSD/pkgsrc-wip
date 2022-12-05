# $NetBSD$

DISTNAME=	git-secret-0.5.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=sobolevn/}
CATEGORIES=	security
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git-secret.io/
COMMENT=	Git subcommand to store your private data inside a git repository
LICENSE=	mit

USE_TOOLS+=	bash:run
DEPENDS+=	gawk-[0-9]*:../../lang/gawk
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-configure
SUBST_MESSAGE.bash=	Fixing misc command paths 
SUBST_SED.bash+=	-e 's,/usr/bin/env bash,${PREFIX}/bin/bash,'
SUBST_SED.bash+=	-e 's,SECRETS_GPG_COMMAND:="gpg",SECRETS_GPG_COMMAND:="${PREFIX}/bin/gpg2",'
SUBST_FILES.bash=	src/version.sh
SUBST_FILES.bash+=	src/main.sh
SUBST_FILES.bash+=	src/commands/git_secret_add.sh
SUBST_FILES.bash+=	src/commands/git_secret_cat.sh
SUBST_FILES.bash+=	src/commands/git_secret_changes.sh
SUBST_FILES.bash+=	src/commands/git_secret_clean.sh
SUBST_FILES.bash+=	src/commands/git_secret_hide.sh
SUBST_FILES.bash+=	src/commands/git_secret_init.sh
SUBST_FILES.bash+=	src/commands/git_secret_list.sh
SUBST_FILES.bash+=	src/commands/git_secret_remove.sh
SUBST_FILES.bash+=	src/commands/git_secret_removeperson.sh
SUBST_FILES.bash+=	src/commands/git_secret_reveal.sh
SUBST_FILES.bash+=	src/commands/git_secret_tell.sh
SUBST_FILES.bash+=	src/commands/git_secret_usage.sh
SUBST_FILES.bash+=	src/commands/git_secret_whoknows.sh
SUBST_FILES.bash+=	src/_utils/_git_secret_tools.sh
SUBST_FILES.bash+=	src/_utils/_git_secret_tools_freebsd.sh
SUBST_FILES.bash+=	src/_utils/_git_secret_tools_linux.sh
SUBST_FILES.bash+=	src/_utils/_git_secret_tools_osx.sh
SUBST_FILES.bash+=	utils/build-utils.sh
SUBST_FILES.bash+=	utils/install.sh
SUBST_FILES.bash+=	utils/tests.sh
SUBST_FILES.bash+=	utils/uninstall.sh

SUBST_CLASSES+=		fixman
SUBST_STAGE.fixman=	pre-configure
SUBST_MESSAGE.fixman=	Fixing paths for man pages
SUBST_SED.fixman+=	-e 's,/share,,'
SUBST_SED.fixman+=	-e 's,/usr/man,/man,'
SUBST_SED.fixman+=	-e 's,PREFIX"/share,PREFIX",'
SUBST_FILES.fixman=	utils/install.sh
SUBST_FILES.fixman+=	utils/uninstall.sh
SUBST_FILES.fixman+=	utils/build-utils.sh

.include "../../mk/bsd.pkg.mk"
