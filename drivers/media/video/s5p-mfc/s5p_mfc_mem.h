/*
 * linux/drivers/media/video/s5p-mfc/s5p_mfc_mem.h
 *
 * Copyright (c) 2010 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __S5P_MFC_MEM_H_
#define __S5P_MFC_MEM_H_ __FILE__

#include <linux/platform_device.h>
#include "s5p_mfc_common.h"

/* Offset base used to differentiate between CAPTURE and OUTPUT
*  while mmaping */

#define MFC_OFFSET_SHIFT	11

#define DST_QUEUE_OFF_BASE      (TASK_SIZE / 2)

#define FIRMWARE_CODE_SIZE	0x60000		/* 384KB */
#define MFC_H264_CTX_BUF_SIZE	0x96000		/* 600KB per H264 instance */
#define MFC_CTX_BUF_SIZE	0x2800		/* 10KB per instance */
#define DESC_BUF_SIZE		0x20000		/* 128KB for DESC buffer */
#define SHARED_BUF_SIZE		0x1000		/* 4KB for shared buffer */

#define DEF_CPB_SIZE		0x40000		/* 512KB */

#define MFC_BANK_A_ALLOC_CTX	0
#define MFC_BANK_B_ALLOC_CTX	1
#define MFC_FW_ALLOC_CTX	0	

#define MFC_BANK1_ALIGN_ORDER	13
#define MFC_BANK2_ALIGN_ORDER	13
#define MFC_FW_ALIGN_ORDER	17

#define MFC_BASE_ALIGN_ORDER	MFC_FW_ALIGN_ORDER

#include <media/videobuf2-dma-contig.h>

static inline size_t s5p_mfc_mem_cookie(void *a, void *b)
{
	/* Same functionality as the vb2_dma_contig_plane_paddr */
	dma_addr_t *paddr = vb2_dma_contig_memops.cookie(b); 

	return *paddr;
}


#endif /* __S5P_MFC_MEM_H_ */
