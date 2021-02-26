# $NetBSD$

PKGNAME=	gitlab-assets-${GITLAB_VERSION}
COMMENT=	Complete software development platform around Git (assets)

USE_TOOLS+=	pax

NO_BUILD=	yes

GITLAB_GROUP?=			gitlab
GITLAB_USER?=			gitlab
GITLAB_HOME?=			/home/git

PLIST_SUBST+=			GITLAB_DIR=${GITLAB_DIR:Q}

PKG_GROUPS=			${GITLAB_GROUP}
PKG_USERS=			${GITLAB_USER}:${GITLAB_GROUP}
PKG_GECOS.${GITLAB_USER}=	GitLab user

MAKE_DIRS_PERMS+=		${GITLAB_HOME} \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0750
MAKE_DIRS_PERMS+=		${GITLAB_HOME}/.ssh \
				${GITLAB_USER} ${GITLAB_GROUP} 0700
MAKE_DIRS_PERMS+=		${GITLAB_HOME}/repositories \
				${GITLAB_USER} ${GITLAB_GROUP} 0700

do-install:
	cd ${WRKSRC} && pax -rw -pmp . \
		${DESTDIR}${PREFIX}/${GITLAB_DIR}

.include "../../wip/gitlab/Makefile.common"
.include "../../mk/bsd.pkg.mk"
