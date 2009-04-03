# $NetBSD: Makefile,v 1.4 2009/04/03 21:50:51 alnsn Exp $

ICC_VERSION=	10.1.022
ICC_SUBPREFIX=	icc10
CATEGORIES=	lang
DISTNAME=	l_cc_p_${ICC_VERSION}
PKGNAME=	${ICC_SUBPREFIX}-${ICC_VERSION}
MASTER_SITES=# empty

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	http://www.intel.com/cd/software/products/asmo-na/eng/compilers/277618.htm
COMMENT=	Intel C++ Compiler for Linux

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=	Intel forbids any redistribution
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
LICENSE=	intel-icc10-license

ICC_PREFIX=		${PREFIX}/${ICC_SUBPREFIX}

ONLY_FOR_PLATFORM+=	NetBSD-*-i386 NetBSD-*-x86_64 \
			Linux-*-i386 Linux-*-x86_64

USE_TOOLS+=		pax

BUILD_DEPENDS+=		rpm2pkg>=2.1:../../pkgtools/rpm2pkg

DEPENDS+=		gcc34>=3.4.6:../../lang/gcc34
GCCBASE=		${BUILDLINK_PREFIX.gcc34}

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base compat
EMUL_REQD=		suse>=10.0

NO_BUILD=		yes

.include "../../mk/bsd.prefs.mk"

PLIST_SUBST+=		ICC_SUBPREFIX=${ICC_SUBPREFIX}

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	/bin/sh
REPLACE_FILES.bash=	${ICC_SUBPREFIX}/bin/icc       \
			${ICC_SUBPREFIX}/bin/icpc      \
			${ICC_SUBPREFIX}/bin/profrun   \
			${ICC_SUBPREFIX}/bin/iccvars.sh

.if ${OPSYS} == "NetBSD"
RM_H=				find ${ICC_VERSION}/include -name *.h -exec rm {} \;
RM_SO=				find ${ICC_VERSION}/lib -name *.so* -exec rm {} \;
STARTFILES=			crt0.o crti.o crtbegin.o
ENDFILES=			crtn.o crtend.o
INTERP=				/usr/libexec/ld.elf_so
DEFINES=			-D__NetBSD__
.else # ${OPSYS} == "Linux"
RM_H=true
RM_SO=true
STARTFILES=no files
ENDFILES=no files
INTERP=#empty
DEFINES=#empty
.endif

SUBST_CLASSES+=			installdir vars

SUBST_MESSAGE.installdir=	Substituting <INSTALLDIR>
SUBST_STAGE.installdir=		pre-configure
SUBST_SED.installdir=		-e 's,<INSTALLDIR>,${ICC_PREFIX},g'
SUBST_FILES.installdir=		${ICC_SUBPREFIX}/bin/icc        \
				${ICC_SUBPREFIX}/bin/icpc       \
				${ICC_SUBPREFIX}/bin/iccvars.sh \
                       		${ICC_SUBPREFIX}/bin/iccvars.csh

SUBST_STAGE.vars=		pre-configure
SUBST_VARS.vars=		GCCBASE INTERP STARTFILES ENDFILES DEFINES
SUBST_FILES.vars=		${ICC_SUBPREFIX}/bin/icc  \
				${ICC_SUBPREFIX}/bin/icpc

PLIST_VARS+=	i386 amd64 linux linux64
.if ${OPSYS} == "Linux"
PLIST.linux=	yes
.endif
.if ${MACHINE_ARCH}=="i386"
ICC_EXTRACT_RPM=data/intel-icc${ICC_VERSION:S/.//g}-${ICC_VERSION}-1.i386.rpm
PLIST.i386=	yes
.else
ICC_EXTRACT_RPM=data/intel-icce${ICC_VERSION:S/.//g}-${ICC_VERSION}-1.em64t.rpm
PLIST.amd64=	yes
.if ${OPSYS} == "Linux"
PLIST.linux64=	yes
.endif
.endif

post-extract:
	cd ${WRKSRC} && rpm2pkg -s 4 ${ICC_EXTRACT_RPM} && \
		rm -rf ${ICC_VERSION}/bin/uninstall.sh     \
			${ICC_VERSION}/eclipse_support/ && \
		${RM_H} && ${RM_SO} && mv ${ICC_VERSION} ${ICC_SUBPREFIX}

do-install:
	cd ${WRKSRC} && find ${ICC_SUBPREFIX} -type f ! -name *.orig | \
		pax -rw -pp ${DESTDIR}${PREFIX}

.include "../../lang/gcc34/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
