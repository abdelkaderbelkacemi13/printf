#include "main.h"

/**
 * init_params - A function to initialize the printing parameters structure.
 *
 * @params: A pointer to the structure to be initialized.
 * @li: The va_list (unused in this function).
 */
void init_params(params_t *params, va_list li)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)li;
}
