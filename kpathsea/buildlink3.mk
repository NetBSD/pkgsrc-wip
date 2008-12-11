# $NetBSD: buildlink3.mk,v 1.4 2008/12/11 01:10:39 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KPATHSEA_BUILDLINK3_MK:=	${KPATHSEA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kpathsea
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkpathsea}
BUILDLINK_PACKAGES+=	kpathsea
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kpathsea

.if ${KPATHSEA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kpathsea+=	kpathsea>=3.5.7
BUILDLINK_PKGSRCDIR.kpathsea?=	../../wip/kpathsea

TEXMFMAIN=	${BUILDLINK_PREFIX.kpathsea}/share/texmf
TEXMFDIST=	${BUILDLINK_PREFIX.kpathsea}/share/texmf-dist
TEXMFDOC=	${BUILDLINK_PREFIX.kpathsea}/share/doc/texmf
TEXMFSYSCONFIG=	${PKG_SYSCONFBASE}/texmf

.  if !empty(TEXMFDIRS)
FILES_SUBST+=		TEXMFDIRS=${TEXMFDIRS:Q}
FILES_SUBST+=		MKTEXLSR="${BUILDLINK_PREFIX.kpathsea}/bin/mktexlsr"
INSTALL_TEMPLATES+=	../../wip/kpathsea/files/texmf-install.tmpl
DEINSTALL_TEMPLATES+=	../../wip/kpathsea/files/texmf-deinstall.tmpl

.    for _texmfdir_ in ${TEXMFDIRS}
PRINT_PLIST_AWK+=       /^${_texmfdir_:S|/|\\/|g}\/ls-R$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${_texmfdir_:S|/|\\/|g}$$/ { next; }
.    endfor
.  endif
.endif	# KPATHSEA_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
