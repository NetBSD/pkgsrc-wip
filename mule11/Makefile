# $NetBSD: Makefile,v 1.2 2015/04/07 02:56:05 makoto Exp $

DISTNAME=		mule-1.1
MASTER_SITES=		${MASTER_SITE_GITHUB:=tsutsui/}
GITHUB_PROJECT=		mule1.1-netbsd
GITHUB_TAG=		p20150328
CATEGORIES=		inputmethod

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		https://github.com/tsutsui/mule1.1-netbsd
COMMENT=		Classical Mule, Muliti-Lingual-Emacs, based on 19.28
LICENSE=		gnu-gpl-v1

USE_TOOLS=		gmake

BROKEN=		See TODO, thanks

SUBST_CLASSES+=		pref
SUBST_SED.pref=		-e 's,/usr/local,${PREFIX},g'
SUBST_MESSAGE.pref=	Convert /usr/local to ${PREFIX}
SUBST_STAGE.pref=	pre-configure
SUBST_FILES.pref=	\
	Makefile \
	build-install \
	dos/emx/makefile \
	dos/go32/makefile \
	etc/FAQ \
	etc/FAQ.jp \
	etc/MACHINES \
	etc/m2ps.1-dist \
	etc/mule.1-dist \
	info/canna-jp \
	info/egg-jp-2 \
	info/emacs-11 \
	info/emacs-13 \
	lisp/paths.el \
	man/canna-jp.texi \
	man/egg-jp.texi \
	man/emacs.texi \
	src/m-ibmps2-aix.h \
	src/mconfig.h-dist \
	src/mconfig.h-netbsd \
	src/paths.h-dist \
	src/ymakefile \

SUBST_CLASSES+=		dest
SUBST_SED.dest=		-e 's,$${BINDIR},$$\{DESTDIR\}$$\{BINDIR\},g'
SUBST_SED.dest+=	-e 's,$${LIBDIR},$$\{DESTDIR\}$$\{LIBDIR\},g'
SUBST_SED.dest+=	-e 's,$${MANDIR},$$\{DESTDIR\}$$\{PKGMANDIR\},g'
SUBST_SED.dest+=	-e 's,^INSTALLFLAGS,\#INSTALLFLAGS,'
SUBST_MESSAGE.dest=	Support to DESTDIR (and disables INSTALLFLAGS)
SUBST_STAGE.dest=	pre-configure
SUBST_FILES.dest=	Makefile

# src/xemacs
#SPECIAL_PERMS=		

.include	"../../mk/bsd.prefs.mk"

pre-configure:
	(cd ${WRKSRC}; \
	${CP} src/config.h-${LOWER_OPSYS}_amd64  \
	      src/config.h-${LOWER_OPSYS}_x86_64; \
	${CP} src/config.h-${LOWER_OPSYS}_${MACHINE_ARCH}  \
	      src/config.h; \
	${CP} src/mconfig.h-${LOWER_OPSYS} src/mconfig.h; \
	)

.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
