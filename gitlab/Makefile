# $NetBSD: Makefile,v 1.5 2014/02/19 11:34:44 makoto Exp $
#
DISTNAME=	gitlab-1.7.1
DISTFILES=	# empty
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gitlabhq/
COMMENT=	GitLab
LICENSE=	mit

WRKSRC=		${WRKDIR}

# fatal: unable to access 'http://github.com/kanchoku/tc.git/': SSL certificate problem: unable to get local issuer certificate
# Add "-c http.sslVerify=false" to git command or,
#PKGSRC_SETENV+=		GIT_SSL_NO_VERIFY=true

#EPENDS+=	ruby[0-9]*-posix-spawn-[0-9]*:../../devel/ruby-posix-spawn
#EPENDS+=	ruby[0-9]*-eventmachine-[0-9]*:../../devel/ruby-eventmachine
#EPENDS+=	ruby[0-9]*-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	ruby[0-9]*-bundler-[0-9]*:../../misc/ruby-bundler
DEPENDS+=	py[0-9]*-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	scons-[0-9]*:../../devel/scons
DEPENDS+=	gitolite-[0-9]*:../../devel/gitolite
#DEPENDS+=	pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives
DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
DEPENDS+=	redis-[0-9]*:../../databases/redis
DEPENDS+=	libexecinfo-[0-9]*:../../devel/libexecinfo
# only for necessary at installation ( 'cp -r' may eliminate following line.)
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
# Does this really help ? .. not checked yet
#EPENDS+=	nodejs-[0-9]*:../../lang/nodejs

# Following lines are too late, passwd and groups should be made before this make
PKG_GROUPS=		gitlab
PKG_USERS=		git:gitlab
PKG_GECOS.gitlab=	GitLab

# Actual install PATH (after INSTALL.script run), this can NOT be easily changed
GITLAB_HOME=		/home/git
# this is pseudo directory, we will copy .destdir -> /home/git in INSTALL script
DEST_GITLAB_HOME=	${DESTDIR}${GITLAB_HOME}

# for file: INSTALL
FILES_SUBST+=	GITLAB_HOME=${GITLAB_HOME:Q}
FILES_SUBST+=	DESTDIR_VAR=${DESTDIR}${GITLAB_HOME:Q}
FILES_SUBST+=	GITLAB_HOME=${GITLAB_HOME:Q}
FILES_SUBST+=	RSYNC=${PREFIX}/bin/rsync

MESSAGE_SUBST+=	GITLAB_HOME=${GITLAB_HOME:Q}

SUBST_CLASSES+=		conf.yml
SUBST_STAGE.conf.yml=	post-build
SUBST_MESSAGE.conf.yml=	Adjust parameter in config.yml
SUBST_FILES.conf.yml=	${DEST_GITLAB_HOME}/gitlab-shell/config.yml
SUBST_SED.conf.yml=	'-e s,/usr/bin,${PREFIX}/bin,'
SUBST_SED.conf.yml+=	'-e s,/home/git,${GITLAB_HOME},'

USE_TOOLS+=	bash gmake

# those are nothing to do with under /home/git
REPLACE_BASH+=	${GITLAB_HOME}/gitlab-shell/support/rewrite-hooks.sh
REPLACE_BASH+=	${GITLAB_HOME}/gitlab-shell/support/truncate_repositories.sh

NO_CHECKSUM=	YES
NO_CONFIGURE=	YES

.include	"../../lang/ruby/replace.mk"
#.include	"../../wip/mk/git-package.mk"
.include	"options.mk"

# Above include does not affect the value,
# so the temporarily fix to MYSQL
OPT_POSTGRES=	echo Skipping

FILES_SUBST+=	OPT_MYSQL=${OPT_MYSQL:Q}
FILES_SUBST+=	OPT_POSTGRES=${OPT_POSTGRES:Q}

# This is not really post-patch, but just utilize (substitute)
# the sequence of build: (first clone to DESTDIR, and will rsync by INSTALL)
post-patch:
# 4. GitLab shell of installation.md
	${MKDIR} ${DEST_GITLAB_HOME}
	(cd ${DEST_GITLAB_HOME} ; \
	git clone https://github.com/gitlabhq/gitlab-shell.git ; \
	cd gitlab-shell ; \
	git checkout v${PKGVERSION_NOREV} ; \
	${CP} config.yml.example config.yml ; \
	)

# do-configure:
# 	${ECHO} do-configure

# the stage of REPLACE_RUBY is too early to apply, so the alternative:
do-build:
	(cd ${DEST_GITLAB_HOME} ; \
	for f in \
		gitlab-shell/bin/check \
		gitlab-shell/bin/gitlab-keys \
		gitlab-shell/bin/gitlab-projects \
		gitlab-shell/bin/gitlab-shell \
		gitlab-shell/bin/install \
		gitlab-shell/hooks/update \
		; do \
                ${SED}  -e '1s|^#! *[a-z0-9_/\.-][a-z0-9_/\.-]*/env *|#!|g' \
                        -e '1s|^#! *[a-z0-9_/\.-]*ruby[0-9\.]*|#!${RUBY}|' $$f > $$f.tmp; \
                if ${CMP} -s $$f $$f.tmp; then \
                        ${RM} $$f.tmp; \
                else \
                        ${MV} $$f.tmp $$f; \
                fi; \
	done; \
	)

do-install:
	${DO_NADA}

.include	"../../textproc/icu/buildlink3.mk"
.include	"../../lang/ruby/buildlink3.mk"
.include	"../../lang/ruby/rubyversion.mk"

.include	"../../mk/bsd.pkg.mk"
