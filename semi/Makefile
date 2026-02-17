# $NetBSD: Makefile,v 1.40 2023/12/24 14:24:52 zafer Exp $
DISTNAME=	semi-1.14.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
# greater than proper
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wanderlust/}
GITHUB_TAG=	8264b478c4f6367ff4cea0c2f13abfda152a13d0


# This fix will be unnecessary for the next release.
#PATCH_SITES=		${MASTER_SITE_LOCAL} #PATCHFILES=		semi-1.14.6-pgg-gpg.patch
#PATCH_DIST_STRIP=	-p0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://git.chise.org/elisp/semi/
COMMENT=	Emacs lisp library to provide MIME feature
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TOOL_DEPENDS+=	qkc-[0-9]*:../../converters/qkc

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/semi \
			${EMACS_INFOPREFIX:C|^${PREFIX}/||}

BUILD_TARGET=	${BUILD_TARGET.${EMACS_FLAVOR}}
INSTALL_TARGET=	${INSTALL_TARGET.${EMACS_FLAVOR}}
MAKEFLAGS=	${MAKEFLAGS.${EMACS_FLAVOR}}

USE_TOOLS+=	makeinfo
INFO_FILES=	yes

EMACS_MODULES=		base
EMACS_BUILDLINK=	# defined

BUILD_TARGET.emacs=	elc
BUILD_TARGET.xemacs=	package
INSTALL_TARGET.emacs=	install
INSTALL_TARGET.xemacs=	install-package
MAKEFLAGS.emacs+=
MAKEFLAGS.xemacs+=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}

pre-build:
	${MKDIR}  ${WRKDIR}/.home/.emacs.d/elpa
# /tmp/wip/semi/work/.home/.emacs.d/elpa
post-build:
	@cd ${WRKSRC}; for i in mime-ui-en mime-ui-ja; do		\
		${RM} -f $${i}.info*;					\
		${CP} $${i}.texi $${i}.texi.orig;			\
		${LOCALBASE}/bin/qkc -Oeu $${i}.texi.orig >$${i}.texi;	\
		makeinfo --force --no-validate $${i}.texi;		\
	done

do-install: plist
	cd ${WRKSRC};							\
	grep -v '^@' ${PLIST} | grep '/site-lisp/semi/' |		\
	while read file; do						\
		file=$$( basename $$file );				\
		${INSTALL_DATA} $$file					\
		    ${DESTDIR}${EMACS_LISPPREFIX}/semi/$$file;		\
	done

post-install:
	cd ${WRKSRC}; for f in mime-ui-*.info mime-*.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_INFOPREFIX};	\
	done
	cd ${WRKSRC}; for f in mime-*.el* mail-mime-setup.el* semi-setup.el* semi-def.el* semi-setup.el* ;  do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_LISPPREFIX};	\
	done

.include "options.mk"

.include "../../editors/emacs/modules.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/flim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
